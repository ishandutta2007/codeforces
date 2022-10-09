uses math;

const maxn = 101010;

// var bit: array[0..maxn] of int64;
// procedure upd(i: longint; val: int64);
// begin
  // inc(i);
  // while i <= maxn do begin
    // inc(bit[i], val);
    // inc(i, i and (-i));
  // end;
// end;
// 
// function get_sum(i: longint): int64;
// var ans: int64 = 0; 
// begin
  // inc(i);
  // while i > 0 do begin
    // inc(ans, bit[i]);
    // dec(i, i and (-i));
  // end;
  // exit(ans);
// end;

type node = record
  nxt: ^node;
  val: longint;
end;
type pnode = ^node;
function new_node(val: longint; nxt: pnode): pnode;
var ans: pnode;
begin
  new(ans); ans^.nxt := nxt; ans^.val := val;
  exit(ans);
end;

procedure push(var st: pnode; val: longint);
begin st := new_node(val, st); end;

function pop(var st: pnode): longint;
var t: pnode;
begin
  pop := st^.val; t := st; st := st^.nxt; dispose(t);
end;

var 
  n, m: longint;
  a: array[0..maxn] of longint;
  st: array[0..maxn] of pnode;
  i: longint;
  t: longint;
  ans, s: int64;

function unique(var a: array of longint): longint;
var i, f: longint;
begin
  f := low(a);
  for i := low(a) to high(a) do begin
    if (i > low(a)) and (a[i] = a[i - 1]) then continue;
    a[f] := a[i];
    inc(f);
  end;
  exit(f - low(a));
end;

begin
  read(n);
  for i := 1 to n do read(a[i]);
  for i := 1 to n do st[i] := nil;
  m := unique(a[1..n]);
  a[0] := -1; a[m + 1] := -1;
  for i := 1 to m do begin
    push(st[a[i]], i);
  end;

  ans := 0; s := 0;
  for i := n downto 1 do begin
    while st[i] <> nil do begin
      t := pop(st[i]);
      if (a[t - 1] < a[t]) and (a[t + 1] < a[t]) then inc(s, n - a[t] + 1)
      else if a[t - 1] < a[t] then inc(s, a[t + 1] - a[t])
      else if a[t + 1] < a[t] then inc(s, a[t - 1] - a[t])
      else begin
        inc(s, min(a[t + 1], a[t - 1]) - a[t]);
        dec(s, n - max(a[t + 1], a[t - 1]) + 1);
      end;
    end;
    inc(ans, s);
  end;
  writeln(ans);
end.
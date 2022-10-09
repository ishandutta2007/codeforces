uses math;

const maxn = 201010;
var 
  n: longint;
  t: int64;
  a: array [0..maxn] of int64;

var
  sum: array [0..maxn] of int64;
  mark: array[0..maxn] of int64;
procedure upd(var bit: array of int64; i: longint; v: int64);
begin
  inc(i);
  while i <= n do begin
    inc(bit[i], v);
    inc(i, i and (-i));
  end;
end;

function get(var bit: array of int64; i: longint): int64;
var ans: int64 = 0;
begin
  inc(i);
  while i > 0 do begin
    inc(ans, bit[i]);
    dec(i, i and (-i));
  end;
  exit(ans);
end;

function getpre(var bit: array of int64; i: int64): int64;
var ans : int64 = 0;
begin
  if i < 0 then exit(0);
  //writeln(stderr, 'getpre ', i, ' ', i div n, ' ', get(bit, n - 1), ' ', i mod n, ' ', get(bit, i mod n));
  ans := (i div n) * get(bit, n - 1);
  inc(ans, get(bit, i mod n));
  exit(ans);
end;

function getseg(var bit: array of int64; l, r: int64): int64;
begin
  ////writeln(stderr, 'getseg ', l, ' ', r, ' ', getpre(bit, r), ' ' , getpre(bit, l - 1));
  exit(getpre(bit, r) - getpre(bit, l - 1));
end;

var
  i: longint;
  ans: int64 = 0;
  curpos, l, r, mid: int64;
begin
  read(n, t);
  //writeln(stderr, n);
  fillchar(sum, sizeof(sum), 0);
  fillchar(mark, sizeof(mark), 0);
  for i := 0 to n - 1 do begin
    read(a[i]);
    upd(sum, i, a[i]);
  end;
  //writeln(stderr, 'cool');
  curpos := 0;
  for i := 1 to n do begin
    //writeln(stderr, curpos);
    l := 0;
    r := 1;
    while getseg(sum, curpos, curpos + r - 1) <= t do begin
      //writeln(stderr, l, ' ', r, ' ', getseg(sum, curpos, curpos + r - 1));
      r := r * 2;
    end;
    //writeln(stderr, 'ok');
    while l < r do begin
      mid := l + (r - l + 1) div 2;
      if getseg(sum, curpos, curpos + mid - 1) <= t then l := mid
      else r := mid - 1;
    end;
    dec(t, getseg(sum, curpos, curpos + l - 1));
    inc(ans, l - getseg(mark, curpos, curpos + l - 1));
    curpos := (curpos + l) mod n;
    upd(sum, curpos, -a[curpos]);
    upd(mark, curpos, 1);
  end;
  writeln(ans);
end.
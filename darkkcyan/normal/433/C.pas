uses math;
const maxn = 101010;
var
  n, m: longint;
  cost: int64;
  val, next, head: array[0..2 * maxn] of longint;
  cur: longint = 0;

procedure add(u, v: longint);
begin
  val[cur] := v;
  next[cur] := head[u];
  head[u] := cur;
  inc(cur);
end;

procedure enter;
var
  i, u, v: longint;
begin
  read(n, m);
  fillchar(next, sizeof(next), 255);
  fillchar(head, sizeof(head), 255);
  read(u);
  cost := 0;
  for i := 2 to m do begin
    read(v);
    if u <> v then begin
      add(u, v);
      add(v, u);
    end;
    inc(cost, int64(abs(u - v)));
    u := v;
  end;
end;

var
  a: array[0..maxn] of longint;

function quickselect(l, r: longint; pos: longint): longint;
var
  i, p, f, t: longint;
begin
  if l = r then exit(a[l]);
  p := random(r - l + 1) + l;
  t := a[p]; a[p] := a[r]; a[r] := t;
  f := l;
  for i := l to r - 1 do begin
    if a[i] < a[r] then begin
      t := a[i]; a[i] := a[f]; a[f] := t;
      inc(f);
    end;
  end;
  p := f;
  for i := p + 1 to r - 1 do begin
    if a[i] = a[r] then begin
      t := a[i]; a[i] := a[f]; a[f] := t;
      inc(f);
    end;
  end;
  f := random(f - p) + p;
  t := a[f]; a[f] := a[r]; a[r] := t;
  if f = pos then exit(a[f]);
  if f > pos then exit(quickselect(l, f - 1, pos));
  exit(quickselect(f + 1, r, pos));
end;

function process(u: longint): int64;
var
  i, n: longint;
  oc: int64; nc: int64;
begin
  nc := 0; oc := 0;
  if head[u] = -1 then exit(0);
  i := head[u];
  n := 0;
  while i <> -1 do begin
    inc(n);
    a[n] := val[i];
    i := next[i];
    inc(oc, int64(abs(u - a[n])));
  end;
  u := quickselect(1, n, (n + 1) div 2);
  for i := 1 to n do inc(nc, int64(abs(u - a[i])));
  exit(nc - oc);
end;

var
  i: longint;
  ans: int64;
begin
  randomize;
  enter;
  ans := cost;
  for i := 1 to n do
    ans := min(ans, cost + process(i));
  writeln(ans);
end.
{$mode objfpc}

const maxn = 3030;
var
  n, m: longint;
  a: array[0..maxn] of longint;

procedure enter;
var i: longint;
begin
  read(n);
  for i := 1 to n do read(a[i]);
  read(m);
end;

procedure swap(var a, b: longint);
var t: longint; begin t := a; a := b; b := t; end;

var
  p, cnt: array[0..maxn] of longint;

function findp(u: longint): longint;
begin
  if p[u] <> u then p[u] := findp(p[u]);
  exit(p[u]);
end;

procedure join(u, v: longint);
begin
  if random(2) = 1 then swap(u, v);
  u := findp(u); v := findp(v);
  if (u = v) then exit;
  p[u] := v;
  inc(cnt[v], cnt[u]);
end;


function getcost(): longint;
var i: longint; ans : longint = 0;
begin
  for i := 1 to n do begin
    p[i] := i;
    cnt[i] := 1;
  end;
  for i := 1 to n do join(i, a[i]);
  for i := 1 to n do 
    if i = findp(i) then inc(ans, cnt[i] - 1);
  exit(ans);
end;

function process(): boolean;
var
  i, f: longint;
  c: longint;
  ans, t1, t2: longint;
begin
  c := getcost();
  ans := maxn * maxn + maxn;
  if c = m then exit(false);
  if c < m then begin
    for i := 2 to n do
      if findp(i) <> findp(1) then begin
        ans := 1 * maxn + i;
        break;
      end;
  end else begin
    for i := 1 to n do
      if i <> a[i] then break;
    for f := i + 1 to n do 
      if findp(i) = findp(f) then begin
        ans := i * maxn + f;
        break;
      end;
  end;
  
  t1 := ans div maxn;
  t2 := ans mod maxn;
  write(t1, ' ', t2, ' ');
  swap(a[t1], a[t2]);
  
  exit(true);
end;

begin
  enter;
  writeln(abs(m - getcost()));
  writeln(stderr, getcost());
  while process() do;
end.
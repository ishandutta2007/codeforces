const maxn = 101010;
var
  n: longint;
  b: array[0..maxn] of integer;
  a: array[1..2, 0..maxn] of longint;

procedure enter;
var
  i: longint;
begin
  read(n);
  for i := 1 to n do begin
    read(b[i]);
    a[b[i]][i] := 1;
    inc(a[1][i], a[1][i - 1]);
    inc(a[2][i], a[2][i - 1]);
  end;
end;

function finds(t: longint): longint;
var
  i, l, r, mid, u, v, p1, p2: longint;
  higher: boolean;
begin
  i := 1;
  p1 := 0;
  p2 := 0;
  //writeln(stderr, 'finds ', t);
  while i <= n do begin
    l := i; r := n;
    while (l < r) do begin
      mid := l + (r - l + 1) div 2;
      u := a[1][mid] - a[1][i - 1];
      v := a[2][mid] - a[2][i - 1];
      higher := true;
      if (u > t) or (v > t) then higher := false;
      if (u = t) and (v = t) then higher := false;
      if (u = t) and (b[mid] = 2) then higher := false;
      if (v = t) and (b[mid] = 1) then higher := false;
      if higher then l := mid
      else r := mid - 1;
    end;
    u := a[1][l] - a[1][i - 1];
    v := a[2][l] - a[2][i - 1];
    if (u <> t) and (v <> t) then exit(-1);
    if (u > v) then inc(p1)
    else inc(p2);
    //writeln(stderr, i, '->', l);
    i := l + 1;
  end;
  if (p1 = p2) then exit(-1);
  if (p1 > p2) then begin
    if b[n] = 1 then exit(p1)
    else exit(-1);
  end
  else if b[n] = 2 then exit(p2)
  else exit(-1);
end;

var
  k: longint;
  ans1, ans2: array[0..maxn] of longint;
  i, f, s: longint;

begin
  enter;
  k := 0;
  for i := 1 to n do begin
    s := finds(i);
    if s = -1 then continue;
    ans1[k] := s;
    ans2[k] := i;
    inc(k);
  end;
  writeln(k);
  i := k - 1;
  while (i >= 0) do begin
    for f := i downto -1 do 
      if (f = -1) or (ans1[i] <> ans1[f]) then break;
    for s := f + 1 to i do writeln(ans1[s], ' ', ans2[s]);
    i := f;
  end;
end.
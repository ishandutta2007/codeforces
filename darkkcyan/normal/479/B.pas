const maxn = 10101;
var
  n, k, i, f: longint;
  a: array[0..maxn] of longint;
  h, l, s, mi, ns: longint;
  s1, s2: array[0..maxn] of longint;

begin
  read(n, k);
  s := 0;
  for i := 1 to n do begin
    read(a[i]);
    inc(s, a[i]);
  end;
  if (s mod n = 0) then mi := 0
  else mi := 1;
  ns := 0;
  for i := 1 to k do begin
    h := 1;
    l := 1;
    for f := 2 to n do begin
      if (a[f] > a[h]) then h := f;
      if (a[f] < a[l]) then l := f;
    end;
    if (a[h] - a[l] = mi) then break;
    dec(a[h]); inc(a[l]);
    inc(ns);
    s1[ns] := h;
    s2[ns] := l;
  end;
  for f := 2 to n do begin
    if (a[f] > a[h]) then h := f;
    if (a[f] < a[l]) then l := f;
  end;
  writeln(a[h] - a[l], ' ', ns);
  for i := 1 to ns do writeln(s1[i], ' ', s2[i]);
end.
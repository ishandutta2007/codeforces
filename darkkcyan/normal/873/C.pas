uses math;
const maxn = 111;
var
  n, m, k: longint;
  a: array[0..maxn, 0..maxn] of longint;
  i, f, ans1, ans2, tans1, tans2, s1, s2: longint;
begin
  read(n, m, k);
  for i := 1 to n do
  for f := 1 to m do begin
    read(a[f][i]);
    inc(a[f][i], a[f][i - 1]);
  end;
  
  ans1 := 0;
  ans2 := 0;
  for f := 1 to m do begin
    tans1 := 0;
    tans2 := 0;
    for i := 1 to n do begin
      if a[f][i] - a[f][i - 1] = 0 then continue;
      s1 := a[f][min(i + k - 1, n)] - a[f][i - 1];
      s2 := a[f][i - 1];
      if s1 < tans1 then continue;
      if s1 > tans1 then begin
        tans1 := s1;
        tans2 := maxn;
      end;
      tans2 := min(tans2, s2);
    end;
    inc(ans1, tans1);
    inc(ans2, tans2);
  end;
  writeln(ans1, ' ', ans2);
end.
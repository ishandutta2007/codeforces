{$Apptype console}
var kk, j, n, m, k, i : longint;
    min, kol : int64;
    d, kom, ans : array [0..1000] of longint;
begin
  read(n, m, k);
  for i := 1 to m do read(d[i]);
  for i := 1 to k do read(kom[i]);
  min := 1000000000000000000;
  for i := 1 to m do
    begin
      kol := 0;
      for j := 1 to k do
        begin
          if kom[j] mod d[i] = 0 then inc(kol);
        end;
      if kol < min then min := kol;
    end;
  kk := 0;
  for i := 1 to m do
    begin
      kol := 0;
      for j := 1 to k do
        begin
          if kom[j] mod d[i] = 0 then inc(kol);
        end;
      if kol = min then
        begin
          inc(kk);
          ans[kk] := i;
        end;
    end;
  writeln(kk);
  for i := 1 to kk do write(ans[i],' ');
end.
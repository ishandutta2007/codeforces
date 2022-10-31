{$Apptype console}
var s1, s2 : string;
    i, kol : longint;
    ans : array [0..4000000] of longint;
    p : int64;
    step, h1, h2 : array [0..4000000] of int64;

function hash1(i, j : longint) : int64;
begin
  hash1 := h1[j] - h1[i - 1] * step[j - i + 1];
end;
function hash2(i, j : longint) : int64;
begin
  hash2 := h2[j] - h2[i - 1] * step[j - i + 1];
end;


begin
  readln(s1);
  readln(s2);
  p := 239;
  step[1] := p;
  for i := 2 to 3000000 do step[i] := step[i - 1] * p;

  h1[1] := ord(s1[1]);
  for i := 1 to length(s1) do  h1[i] := h1[i - 1] * p + ord(s1[i]);
  h2[1] := ord(s2[1]);
  for i := 1 to length(s2) do  h2[i] := h2[i - 1] * p + ord(s2[i]);
  kol := 0;
  if hash1(2, length(s1)) = h2[length(s2)] then
    begin
      inc(kol);
      ans[kol] := 1;
    end;
  for i := 2 to length(s1) - 1 do
    begin
      if (h1[i - 1] = h2[i - 1]) and (hash1(i + 1, length(s1)) = hash2(i, length(s2)))
       then
        begin
          inc(kol);
          ans[kol] := i;
        end;
    end;
  if h1[length(s1) - 1] = h2[length(s2)] then
    begin
      inc(kol);
      ans[kol] := length(s1);
    end;
  writeln(kol);
  for i := 1 to kol do write(ans[i],' ');
end.
program p;
var
  i, n, l, r: integer;
  first, second, count: array of integer;
  answer: boolean;
begin
  answer := true;
  readln(n, l, r);
  SetLength(first,n);
  SetLength(second,n);
  SetLength(count,n);
  l := l - 1;
  r := r - 1;
  for i := 0 to n - 1 do
  begin
    read(first[i]);
  end;
  for i := 0 to n - 1 do
  begin
    read(second[i]);
  end;
  
  for i := 0 to n - 1 do
  begin
    if ((i < l) or (i > r)) and (first[i] <> second[i]) then answer := false
    else
    begin
      count[first[i] - 1] := count[first[i] - 1] + 1;
      count[second[i] - 1] := count[second[i] - 1] - 1;
    end;
  end;
  
  for i := 0 to n - 1 do
  begin
    if count[i] <> 0 then answer := false;
  end;
  
  if answer = false then writeln('LIE')
  else writeln('TRUTH');
end.
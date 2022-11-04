program B1;
var n, b, s, t, i, colvo:integer;
    a:array[1..100000] of integer;
    c:array[1..100000] of integer;
begin
  readln(n, s, t);
  for i:=1 to n do
  begin
    read(a[i]);
    c[i] := 0;
  end;
  colvo:=0;
  while (s<>t) do
  begin
    c[s] := 1;
    if c[a[s]] = 1 then
    begin
      colvo:=-1;
      s:=t;
    end
    else
    begin
      colvo:=colvo+1;
      s:=a[s];
    end;
  end;
  writeln(colvo);
end.
program COD2_1;
var i, b, n:integer;
    a:array[1..1000] of integer;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(b);
    a[b]:=a[b]+1;
  end;
  b:=0;
  for i:=1 to 1000 do
  begin
    if  n mod 2 = 0 then
    begin
      if a[i] >n div 2 then b:=1;
    end
    else
    begin
      if a[i]>(n div 2)+1 then b:=b+1;
    end;
  end;
  if b=1 then writeln('NO')
  else writeln('YES');
end.
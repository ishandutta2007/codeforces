program A189;
var n, e, a, b, c, d:int64;
    i:integer;
begin
  readln(n);
  a:=1;
  b:=0;
  e:=0;
  while(a<n) do
  begin
    a:=a*10;
    b:=b+1;
  end;
  a:=10;
  for i:=1 to b do
  begin
    c:=(n mod a - n mod (a div 10)) div (a div 10);
    if ((c<>1) and (c<>4)) then
    begin
      d:=1;
      break;
    end
    else
    begin
      if c=4 then
      begin
       e:=e+1;
       if e>2 then d:=1;
      end
      else e:=0;
    end;
    a:=a*10;
  end;
  if c=4 then d:=1;
  if d=1 then writeln('NO')
  else writeln('YES');
end.
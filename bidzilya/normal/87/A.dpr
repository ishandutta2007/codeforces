var
  a,b:integer;

function nod(x,y:integer):integer;
begin
  while (x>0)and(y>0) do if x>=y then x:=x mod y else y:=y mod x;
  result:=y+x;
end;

begin
  readln(a,b);
  if nod(a,b)=abs(a-b) then writeln('Equal') else
    if a>b then writeln('Masha') else
      writeln('Dasha');
end.
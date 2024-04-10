program task_1;

{$APPTYPE CONSOLE}
var n,z,i,x,y,tz,tx,ty:integer;
begin
  read(n); x:=0; y:=0; z:=0;
  for i:=1 to n do begin
    read(tx,ty,tz);
    x:=x+tx; y:=y+ty; z:=z+tz;
  end;
  if (x=0)and(y=0)and(z=0)then write('YES')else
    write('NO');
end.
{$APPTYPE CONSOLE}
uses Math;
var r,g,b,tt,ti:integer;
begin
  ti:=1;
  tt:=-1;
  if (r=0)and(g=0)and(b=0)then begin write(0); halt; end;
  readln(r,g,b);
  while (r>0)or(g>0)or(b>0)do
  begin
    tt:=tt+1;
    if (ti=1)then r:=max(0,r-2);
    if (ti=2)then g:=max(0,g-2);
    if (ti=3)then b:=max(0,b-2);
    inc(ti);
    if (ti=4)then ti:=1;
  end;
  write(tt+30);
end.
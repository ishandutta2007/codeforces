program task_2;

{$APPTYPE CONSOLE}
uses
  Math,
  SysUtils;
var k,n,m,i: integer;
    ans,dx,dy,cx,cy,x,y: int64;

begin
  read(n,m,cy,cx,k);
  ans:=0;
  for i:=1 to k do begin
    read(dy,dx);
    if (dy>=0)then y:=n - cy else y:=cy-1;
    if (dx>=0)then x:=m - cx else x:=cx-1;
    if (dy=0)then y:=maxint else y:=abs(y div dy);
    if (dx=0)then x:=maxint else x:=abs(x div dx);
    ans:=ans+min(y, x);
    cy:=cy+min(y,x)*dy;
    cx:=cx+min(y,x)*dx;
  end;
  write(ans);
end.
program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var l,k,a,b,n: integer;

function nod(x,y: integer): integer;
begin
  while (x>0)and(y>0)do
    if (x>y)then
      x:=x mod y
    else
      y:=y mod x;
  nod:=x+y;
end;

begin
  read(a,b,n);
  while (true)do begin
    l:=nod(a,n);
    if (n<l)then begin
      k:=1;
      break;
    end;
    dec(n,l);
    l:=nod(b,n);
    if (n<l)then begin
      k:=0;
      break;
    end;
    dec(n,l);
  end;
  write(k);
end.
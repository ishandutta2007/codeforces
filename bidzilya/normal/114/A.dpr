program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var k,l,t,i: int64;

begin
  read(k,l);
  i:=0;t:=k;
  while (t<l)do begin
    t:=t*k;
    inc(i);
  end;
  if (t=l)then begin
    writeln('YES');
    writeln(i);
  end else
    writeln('NO');
end.
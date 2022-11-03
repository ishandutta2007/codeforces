program task_2;
{$APPTYPE CONSOLE}
uses SysUtils;
var a,b:integer;
    s1,s2:string;

function mask(t:string):string;
var i:integer;
    tmp:string;
begin
  tmp:='';
  for i:=1 to length(t)do
    if (t[i]='4')or(t[i]='7')then
      tmp:=tmp+t[i];
  mask:=tmp;
end;

begin
  read(a,b);
  if (b>a)then begin
    write(b);
    halt;
  end;
  inc(a);
  s1:=inttostr(a);
  s2:=inttostr(b);
  while (mask(s1)<>s2)do begin
    inc(a);
    s1:=inttostr(a);
  end;
  write(s1);
end.
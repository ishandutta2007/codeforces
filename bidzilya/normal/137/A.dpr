{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  ans,count:integer;
  c,tc:char;
begin
  ans:=-1;
  tc:='X';
  read(c);
  while (c='C')or(c='P')do
  begin
    if (tc<>c)or(count=5)then
    begin
      tc:=c;
      count:=0;
      inc(ans);
    end;
    inc(count);
    read(c);
  end;
  inc(ans);
  write(ans);
  read(ans);
end.
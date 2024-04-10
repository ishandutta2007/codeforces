program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type TSet=record
  mintime,maxtime,uptime:Integer;
end;
var
  d,sumtime,i,summaxtime,summintime:Integer;
  sets:array[1..30] of TSet;
begin
  Readln(d,sumtime);
  for i:=1 to d do
    Readln(sets[i].mintime,sets[i].maxtime);
  summaxtime:=0; summintime:=0;
  for i:=1 to d do
  begin
    Inc(summaxtime,sets[i].maxtime);
    Inc(summintime,sets[i].mintime);
  end;
  if (sumtime<summintime) or (sumtime>summaxtime) then
  begin
    Writeln('NO');
    Halt(0);
  end;
  Writeln('YES');
  sumtime:=sumtime-summintime;
  for i:=1 to d do
  begin
    if sumtime>=sets[i].maxtime-sets[i].mintime then
    begin
      sets[i].uptime:=sets[i].maxtime-sets[i].mintime;
      Dec(sumtime,sets[i].maxtime-sets[i].mintime);
    end
    else
    begin
      sets[i].uptime:=sumtime;
      sumtime:=0;
    end;
  end;
  for i:=1 to d do
    write(sets[i].mintime+sets[i].uptime,' ');
end.
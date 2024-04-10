program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type Up=record
  name:String;
  score:Integer;
end;
var
  n,i,p,k,j,m,max:Integer;
  ups:array[1..1000] of Up;
  scores:array[1..1000] of Up;
  winners:array[1..1000] of Boolean;
  S:String;
procedure Clear;
var
  f:Integer;
begin
  for f:=1 to 1000 do
  begin
    scores[i].name:='';
    scores[i].score:=0;
  end;
end;
begin
  Readln(n);
  for i:=1 to n do
  begin
    Readln(S);
    p:=Pos(' ',S);
    ups[i].name:=Copy(S,1,p-1);
    ups[i].score:=StrToInt(Copy(S,p+1,Length(s)-p));
  end;
  k:=0;
  Clear;
  for i:=1 to n do
  begin
    m:=0;
    for j:=1 to k do
    begin
      if scores[j].name=ups[i].name then
      begin
        Inc(scores[j].score,ups[i].score);
        m:=j;
      end;
    end;
    if m=0 then
    begin
      Inc(k);
      scores[k].name:=ups[i].name;
      scores[k].score:=ups[i].score;
    end;
  end;
  max:=0;
  for i:=1 to n do
    if scores[i].score>max then max:=scores[i].score;
  for i:=1 to n do winners[i]:=false;
  for i:=1 to n do
    if scores[i].score>=max then winners[i]:=True;
  for i:=1 to n do
    scores[i].score:=0;
  for i:=1 to n do
  begin
    for j:=1 to k do
    begin
      if scores[j].name=ups[i].name then
      begin
        Inc(scores[j].score,ups[i].score);
        if (scores[j].score>=max) and (winners[j]=True) then
        begin
          Writeln(scores[j].name);
          Halt(0);
        end;
      end;
    end;
  end;
end.
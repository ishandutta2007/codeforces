program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils, Math;
var ans,t: string;
    a,d: array['a'..'z']of integer;
    i,lens: integer;
    c: char;

procedure calc(v: integer);
var i: integer;
    b: array['a'..'z']of integer;
    ok,c: char;
    ta: string;
begin
  for c:='a' to 'z'do
    b[c]:=a[c];
  for c:='a' to 'z' do
    dec(b[c],d[c]);
  for c:='a' to 'z' do
    if (b[c]<0)then
      exit;
  ok:=' ';
  c:=chr(ord(t[v])+1);
  for c:=c to 'z' do
    if (b[c]>0)then begin
      ok:=c;
      break;
    end;
  if (ok=' ')then exit;
  ta:=copy(t,1,v-1)+ok;
  dec(b[ok]);
  for c:='a' to 'z' do
    while (b[c]>0)do begin
      dec(b[c]);
      ta:=ta+c;
    end;
  ans:=ta;
end;

procedure calc2;
var c: char;
    i: integer;
    ta: string;
begin
  for i:=1 to length(t)do
    dec(a[t[i]]);
  for c:='a' to 'z' do
    if (a[c]<0)then
      exit;
  ta:=t;
  for c:='a' to 'z' do
    while (a[c]>0)do begin
      dec(a[c]);
      ta:=ta+c;
    end;
  if (ans='')or(ta<ans)then
    ans:=ta;
end;

begin
  readln(t);
  lens:=length(t);
  for c:='a' to 'z' do a[c]:=0;
  for c:='a' to 'z' do d[c]:=0;
  for i:=1 to lens do
    inc(a[t[i]]);
  readln(t);
  for i:=1 to min(length(t),lens) do
    inc(d[t[i]]);
  ans:='';
  for i:=min(lens,length(t)) downto 1 do begin
    dec(d[t[i]]);
    calc(i);
    if (ans<>'')then break;
  end;
  if (lens>length(t))then
    calc2;
  if (ans='')then
    write(-1)
  else
    write(ans);
end.
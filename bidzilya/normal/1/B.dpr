program task_2;

{$APPTYPE CONSOLE}
uses SysUtils;
var n,p,i,x,y: integer;
    s: string;

function check1:boolean;
var i: integer;
begin
  if (s[1]<>'R')then begin
    check1:=false;
    exit;
  end;
  p:=pos('C',s);
  if (p=-1)or(p=length(s))or(p=2)then begin
    check1:=false;
    exit;
  end;
  for i:=2 to p-1 do
    if not (s[i] in ['0'..'9'])then begin
      check1:=false;
      exit;
    end;
  for i:=p+1 to length(s)do
    if not (s[i] in ['0'..'9'])then begin
      check1:=false;
      exit;
    end;
  check1:=true;
end;
function get(x: integer): string;
var t: string;
    i,len: integer;
    a: array[1..6]of integer;
begin
    len:=0;
    while (x>0)do begin
      inc(len);
      a[len]:=x mod 26;
      x:=x div 26;
    end;
    for i:=1 to len-1 do
      if (a[i]<=0)then begin
        a[i]:=a[i]+26;
        dec(a[i+1]);
      end;
    t:='';
    while (a[len]=0)do dec(len);
    for i:=len downto 1 do
        t:=t+chr(ord('A')+a[i]-1);
    get:=t;
end;
begin
  readln(n);
  for n:=1 to n do begin
    readln(s);
    if (check1)then begin
      x:=strtoint(copy(s,2,p-2));
      y:=strtoint(copy(s,p+1,length(s)-p));
      write(get(y));
      write(x);
      writeln;
    end else begin
      x:=0;y:=0;
      i:=1;
      while (s[i] in ['A'..'Z'])do begin
        y:=y*26+ord(s[i])-ord('A')+1;
        inc(i);
      end;
      while (i<=length(s))do begin
        x:=x*10+ord(s[i])-ord('0');
        inc(i);
      end;
      writeln('R',x,'C',y);
    end;
  end;
end.
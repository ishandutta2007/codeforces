program Task2;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var j,ind,i,c,n,m: integer;
    name: array[1..1000]of string;
    t: array[1..1000]of integer;
    s: string;
    k: double;

begin
  readln(n);
  m:=0;
  for i:=1 to n do begin
    readln(s);
    c:=strtoint(copy(s,pos(' ',s)+1,length(s)-pos(' ',s)));
    delete(s,pos(' ',s),length(s)-pos(' ',s)+1);
    ind:=-1;
    for j:=1 to m do
      if (name[j]=s)then begin
        ind:=j;
        break;
      end;
    if (ind=-1)then begin
      inc(m);
      name[m]:=s;
      t[m]:=c;
    end else
      t[ind]:=max(t[ind],c);
  end;
  writeln(m);
  for i:=1 to m do begin
    writeln(name[i],' ');
    c:=0;
    for j:=1 to m do
      if (t[j]>t[i])then
        inc(c);
    k:=c/m*100;
    if (k>50)then
      writeln('noob')
    else
    if (k>20)then
      writeln('random')
    else
    if (k>10)then
      writeln('average')
    else
    if (k>1)then
      writeln('hardcore')
    else
      writeln('pro');
  end;
end.
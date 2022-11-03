program Task1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const md = round(1e9)+7;
var t,s1,s2: string;
    n,i,col,k,j,l: integer;
    cnt0,cnt1,buf0,buf1: integer;
    r: array[0..1000]of integer;
begin
  readln(s1);
  readln(s2);
  readln(k);
  col:=0;
  if (s1=s2)then begin
    inc(col);
    r[col]:=0;
  end;
  n:=length(s1)-1;
  for i:=1 to n do begin
    t:=copy(s1,i+1,n+1-i)+copy(s1,1,i);
    if (t=s2)Then begin
      inc(col);
      r[col]:=i;
    end;
  end;
  if (col=0)then begin
    write(0);
    halt;
  end;

  cnt0:=1;
  cnt1:=0;

  for i:=1 to k do begin
    buf0:=cnt0;
    buf1:=cnt1;
    cnt0:=0;
    for j:=1 to n do
      cnt0:=(cnt0+buf1)mod md;
    cnt1:=buf0;
    for j:=1 to n-1 do
      cnt1:=(cnt1+buf1)mod md;
  end;

  j:=0;
  for i:=1 to col do
    if (r[i]=0)then
      j:=(j+cnt0)mod md
    else
      j:=(j+cnt1)mod md;
  write(j);
end.
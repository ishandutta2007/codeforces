{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  ans,n,i,m,j,w,l:integer;
  s,rulonw,rulonh,stenah,stenal:array[1..500]of integer;
  tmp:real;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(w,l,stenah[i]);
    stenal[i]:=2*w+2*l;
  end;
  readln(m);
  for i:=1 to m do
    readln(rulonh[i],rulonw[i],s[i]);

  ans:=0;
  for i:=1 to n do
  begin
    l:=maxint;
    for j:=1 to m do
    begin
      tmp:=rulonh[j]/stenah[i];
      if tmp<1 then
        continue;
      w:=round(tmp);
      if w>tmp then
        dec(w);
      tmp:=stenal[i]/(w*rulonw[j]);
      w:=round(tmp);
      if w<tmp then
        inc(w);
      if s[j]*w<l then
        l:=s[j]*w;
    end;
    inc(ans,l);
  end;
  write(ans);
end.
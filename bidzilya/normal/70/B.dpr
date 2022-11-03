program project1;

{$apptype console}

uses Math, SysUtils;
var n,i,j,k,ans,m: integer;
    a: array[1..10000]of integer;
    s: string;
begin
  readln(n);
  readln(s);
  m:=0;
  while (length(s)>0)do begin
    while (length(s)>0)and(s[1]=' ')do
      delete(s,1,1);
    i:=pos('.',s);
    j:=pos('!',s);
    k:=pos('?',s);
    if (i=0)then i:=maxint;
    if (j=0)then j:=maxint;
    if (k=0)then k:=maxint;
    i:=min(i,min(j,k));
    inc(m);
    a[m]:=i;
    delete(s,1,i);
  end;
  for i:=1 to m do
    if (a[i]>n)then begin
      write('Impossible');
      halt;
    end;
  ans:=0;
  j:=a[1];
  for i:=2 to m do
    if (j+a[i]+1<=n)then
      j:=j+a[i]+1
    else begin
      inc(ans);
      j:=a[i];
    end;
  inc(ans);
  write(ans);
end.
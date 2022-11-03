program Task1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var tk,ans,tans,ind,n,m,k,i,j,v1,v2: integer;
    a,b,c: array[1..10,1..100]of integer;
    t: array[1..100]of integer;

begin
  readln(n,m,k);
  for i:=1 to n do begin
    readln;
    for j:=1 to m do
      readln(a[i,j],b[i,j],c[i,j]);
  end;

  ans:=0;
  for v1:=1 to n do
    for v2:=1 to n do begin
      tans:=0;
      for i:=1 to m do
        t[i]:=b[v2,i]-a[v1,i];
      tk:=k;
      for i:=1 to m do begin
        ind:=-1;
        for j:=1 to m do
          if (ind=-1)or(t[j]>t[ind])then
            ind:=j;
        if (ind=-1)or(t[ind]<0)then
          break;
        if (c[v1,ind]<tk)then begin
          tans:=tans+t[ind]*c[v1,ind];
          tk:=tk-c[v1,ind];
          t[ind]:=-1;
        end else begin
          tans:=tans+t[ind]*tk;
          tk:=0;
          t[ind]:=-1;
        end;
      end;
      if (tans>ans)then
        ans:=tans;
    end;
  write(ans);
end.
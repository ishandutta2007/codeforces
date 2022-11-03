{$APPTYPE CONSOLE}
var a:array[1..5000]of char;
    u,d,l,r,tu:array[0..5000]of integer;
    i,j,n,m,nm,tl,ans,count,tans:integer;
    c:char;

procedure dfs(ind:integer);
begin
  inc(tans);
  l[r[ind]]:=l[ind]; r[l[ind]]:=r[ind];
  u[d[ind]]:=u[ind]; d[u[ind]]:=d[ind];
  if (a[ind]='U')and(u[ind]<>0)then dfs(u[ind])else
  if (a[ind]='D')and(d[ind]<>0)then dfs(d[ind])else
  if (a[ind]='R')and(r[ind]<>0)then dfs(r[ind])else
  if (a[ind]='L')and(l[ind]<>0)then dfs(l[ind]);
  r[l[ind]]:=ind; l[r[ind]]:=ind;
  u[d[ind]]:=ind; d[u[ind]]:=ind;
end;

begin
 { assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);}
  fillchar(u,sizeof(u),0);
  fillchar(d,sizeof(d),0);
  fillchar(tu,sizeof(tu),0);
  fillchar(l,sizeof(l),0);
  fillchar(r,sizeof(r),0);
  readln(n,m); nm:=0;
  for i:=1 to n do
  begin
    tl:=0;
    for j:=1 to m do
    begin
      read(c);
      if (c='.')then continue;
      inc(nm); a[nm]:=c;
      r[tl]:=nm; l[nm]:=tl; tl:=nm;
      d[tu[j]]:=nm; u[nm]:=tu[j]; tu[j]:=nm;
    end;
    readln;
  end;
  ans:=0;count:=0;
  for i:=1 to nm do
  begin
    tans:=0;
    dfs(i);
    if (tans>ans)then begin ans:=tans; count:=1; end else
    if (tans=ans)then inc(count);
  end;
  write(ans,' ',count);
end.
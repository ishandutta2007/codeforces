{$APPTYPE CONSOLE}

var l,i,j,n,w,h,tmp,ka:integer;
    x1,y1,x2,y2:array[1..1000]of integer;
    ans:array[1..1000]of integer;

procedure dfs(xx1,yy1,xx2,yy2:integer);
var ind,i:integer;
begin
  ind:=-1;
  for i:=1 to n do
    if ((x1[i]=xx1)and(x2[i]=xx2)and(y1[i]>=yy1)and(y2[i]<=yy2))or
       ((y1[i]=yy1)and(y2[i]=yy2)and(x1[i]>=xx1)and(x2[i]<=xx2))then
    begin
      ind:=i;
      break;
    end;
  if ind=-1 then
  begin
    inc(ka);
    ans[ka]:=(xx2-xx1)*(yy2-yy1);
    exit;
  end;
  x1[n+1]:=x1[ind];x2[n+1]:=x2[ind];y1[n+1]:=y1[ind];y2[n+1]:=y2[ind];
  x1[ind]:=x1[n];y1[ind]:=y1[n];x2[ind]:=x2[n];y2[ind]:=y2[n];
  ind:=n+1; dec(n);
  if (y2[ind]-y1[ind]<>0)then
  begin
    dfs(xx1,yy1,x1[ind],yy2);
    dfs(x1[ind],yy1,xx2,yy2);
  end else
  begin
    dfs(xx1,yy1,xx2,y1[ind]);
    dfs(xx1,y1[ind],xx2,yy2);
  end;
end;

begin
 { assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);}
  readln(w,h,n); ka:=0;
  for i:=1 to n do read(x1[i],y1[i],x2[i],y2[i]);
  dfs(0,0,w,h);
  for i:=1 to ka-1 do
    for j:=i+1 to ka do
      if ans[j]<ans[i]then begin
        tmp:=ans[i]; ans[i]:=ans[j]; ans[j]:=tmp;
      end;
  for i:=1 to ka do write(ans[i],' ');
end.
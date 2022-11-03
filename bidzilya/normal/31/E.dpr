{$APPTYPE CONSOLE}

var n,i,j,k:integer;
    p,dp,zh,zm:array[0..18,0..18]of int64;
    a:array[1..36]of int64;
    s:array[0..17]of int64;
    c:char;

procedure getans(x,y:integer);
var l1,l2:int64;
begin
  if (x+y=0)then exit;
  l1:=0; l2:=0;
  if (x>0)then l1:=zh[x-1,y]+zm[x-1,y]+a[x+y]*s[x];
  if (y>0)then l2:=zh[x,y-1]+zm[x,y-1]+a[x+y]*s[y];
  if (l1>l2)or(y<1)then
    begin
      dp[x,y]:=l1;
      zh[x,y]:=zh[x-1,y]+a[x+y]*s[x];
      zm[x,y]:=zm[x-1,y];
      p[x,y]:=1;
    end
    else
    begin
      dp[x,y]:=l2;
      zh[x,y]:=zh[x,y-1];
      zm[x,y]:=zm[x,y-1]+a[x+y]*s[y];
      p[x,y]:=2;
    end;
end;

procedure writeans(x,y:integer);
begin
  if (p[x,y]=-1)then exit;
  if (p[x,y]=2)then begin writeans(x,y-1); write('M'); end
    else
    begin writeans(x-1,y); write('H'); end;
end;

begin
  readln(n);
  read(c); i:=0;
  while (c in ['0'..'9'])do
  begin
    inc(i);
    a[i]:=ord(c)-ord('0');
    read(c);
  end;
  s[n]:=1; for i:=n-1 downto 1 do s[i]:=s[i+1]*10;
  fillchar(p,sizeof(p),-1);
  fillchar(zm,sizeof(zm),0);
  fillchar(zh,sizeof(zh),0);
  for i:=0 to n do
    for j:=0 to n do
      getans(i,j);

  writeans(n,n);
end.
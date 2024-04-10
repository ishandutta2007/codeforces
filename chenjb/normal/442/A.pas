var
  n:longint;
  num:array[1..5,1..5]of longint;
  v:array[1..5,1..5]of boolean;
  v1,v2:array[1..5]of boolean;
  cnt,ans:longint;
  c1,c2:char;
function judge(x,y:longint):boolean;
var
  t,i:longint;
begin
  if v1[x] and v2[y] then exit(true);
  t:=0;
  if v1[x] then
    for i:=1 to 5 do if v[x,i] then inc(t);
  if t=1 then exit(true);
  t:=0;
  if v2[y] then
    for i:=1 to 5 do if v[i,y] then inc(t);
  if t=1 then exit(true);
  exit(false);
end;
procedure clear(x,y:longint);
var
  i,j:longint;
begin
  v[x,y]:=false;
  dec(cnt);
  for i:=1 to 5 do
    if v[i,y] then if judge(i,y) then clear(i,y);
  for i:=1 to 5 do
    if v[x,i] then if judge(x,i) then clear(x,i);
end;
procedure calc;
var
  i,j:longint;
begin
  for i:=1 to 5 do
    for j:=1 to 5 do
      if v[i,j] then if judge(i,j) then clear(i,j);
end;
procedure dfs(step:longint);
var
  i,j,k,t:longint;
  tv:array[1..5,1..5]of boolean;
begin
  if step>ans then exit;
  if cnt<=1 then
  begin
    if ans>step then ans:=step;
    exit;
  end;
  for i:=1 to 5 do
    for j:=1 to 5 do tv[i,j]:=v[i,j];
  for i:=1 to 5 do
    if not v1[i] then
    begin
      t:=cnt;
      v1[i]:=true;
      calc;
      dfs(step+1);
      cnt:=t;
      for j:=1 to 5 do
        for k:=1 to 5 do v[j,k]:=tv[j,k];
      v1[i]:=false;
    end;
  for i:=1 to 5 do
    if not v2[i] then
    begin
      t:=cnt;
      v2[i]:=true;
      calc;
      dfs(step+1);
      cnt:=t;
      for j:=1 to 5 do
        for k:=1 to 5 do v[j,k]:=tv[j,k];
      v2[i]:=false;
    end;
end;
function cc(c:char):longint;
begin
  if c='R'then exit(1);
  if c='G'then exit(2);
  if c='B'then exit(3);
  if c='Y'then exit(4);
  if c='W'then exit(5);
end;
var
  i:longint;
begin

  readln(n);
  fillchar(num,sizeof(num),0);
  fillchar(v,sizeof(v),false);
  cnt:=0;
  for i:=1 to n do
  begin
    if i<>1 then read(c1);
    read(c1);
    read(c2);
    if i=85 then
    begin
      c1:=c1;
    end;
    inc(num[cc(c1),ord(c2)-48]);
   // writeln(i);
    if v[cc(c1),ord(c2)-48]=false then
    begin
      v[cc(c1),ord(c2)-48]:=true;
      inc(cnt);
    end;
  end;
  ans:=2147483647;
  fillchar(v1,sizeof(v1),false);
  fillchar(v2,sizeof(v2),false);
  dfs(0);
  writeln(ans);

end.
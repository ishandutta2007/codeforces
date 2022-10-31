var
  a:Array[1..4]of longint;
  s:ansistring;
  i,n,max:longint;
  c:char;
  ans,maxp:int64;
const
  inf=1000000007;
function cc(c:char):longint;
begin
  if c='A' then exit(1);
  if c='G' then exit(2);
  if c='C' then exit(3);
  if c='T' then exit(4);
end;
begin
 
  readln(n);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
  begin
    read(c);
    inc(a[cc(c)]);
  end;
  max:=0;
  maxp:=0;
  for i:=1 to 4 do
    if a[i]>max then
    begin
      max:=a[i];
      maxp:=1;
    end
    else
    if a[i]=max then inc(maxp);
  ans:=1;
  for i:=1 to n do
    ans:=ans*maxp mod inf;
  writeln(ans);

end.
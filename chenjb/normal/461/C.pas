var
  a:array[1..101000]of longint;
  l,r,ss,ee,n,q,way,i,ii,j,p:longint;
  flag:boolean;
function lowbit(x:longint):longint;
begin
  exit(x and (-x));
end;
procedure insert(x,k:longint);
begin
  while x<=n do
  begin
    a[x]:=a[x]+k;
    x:=x+lowbit(x);
  end;
end;
function getsum(x:longint):longint;
var
  ans:longint;
begin
  ans:=0;
  while x>0 do
  begin
    ans:=ans+a[x];
    x:=x-lowbit(x);
  end;
  exit(ans);
end;
begin

  readln(n,q);
  flag:=false;
  fillchar(a,sizeof(a),0);
  for i:=1 to n do insert(i,1);
  ss:=1;
  ee:=n;
  for ii:=1 to q do
  begin
    read(way);
    if way=1 then
    begin
      readln(p);
      if p<=(ee-ss+1)div 2 then
      begin
        if not flag then
        begin
          i:=p+ss-1;
          j:=p+ss;
          while i>=ss do
          begin
            insert(j,getsum(i)-getsum(i-1));
            dec(i);
            inc(j);
          end;
          ss:=ss+p;
        end
        else
        begin
          i:=ee-p;
          j:=ee-p+1;
          while j<=ee do
          begin
            insert(i,getsum(j)-getsum(j-1));
            dec(i);
            inc(j);
          end;
          ee:=ee-p;
        end;
      end
      else
      begin
        if not flag then
        begin
          i:=ss+p-1;
          j:=ss+p;
          while j<=ee do
          begin
            insert(i,getsum(j)-getsum(j-1));
            inc(j);
            dec(i);
          end;
          ee:=ss+p-1;
          flag:=true;
        end
        else
        begin
          i:=ee-p;
          j:=ee-p+1;
          while i>=ss do
          begin
            insert(j,getsum(i)-getsum(i-1)) ;
            dec(i);
            inc(j);
          end;
          ss:=ee-p+1;
          flag:=false;
        end;
      end;
    end
    else if way=2 then
    begin
      readln(l,r);
      inc(l);
      if not flag then writeln(getsum(ss+r-1)-getsum(ss+l-1-1))
      else writeln(getsum(ee-l+1)-getsum(ee-r+1-1));
    end;
  end;

end.
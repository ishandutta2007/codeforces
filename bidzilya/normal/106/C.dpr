var
  a,b,d,l,tmp,c,n,m,i,j:integer;
  ans:array[0..10,0..1000]of integer;
  
begin
  read(n,m,c,d);
  for i:=0 to n do
    ans[0,i]:=(i div c)*d;
  for i:=1 to m do begin
    read(a,b,c,d);
    ans[i]:=ans[i-1];
    for j:=1 to a div b do
      for l:=j*c to n do begin
        tmp:=ans[i-1,l-j*c]+j*d;
        if tmp>ans[i,l] then ans[i,l]:=tmp;
      end;
  end;
  write(ans[m,n]);
end.
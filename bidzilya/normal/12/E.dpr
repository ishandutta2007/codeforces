var
  a:array[1..1000,1..1000]of integer;
  str:array[1..1000,1..999]of byte;
  i,j,k,n:integer;
  
procedure getsim(y,x:integer);
begin
  a[x,y]:=a[y,x];
  str[x,a[x,y]]:=1;
end;  
  
begin
  read(n);
  for i:=1 to n do 
    a[i,i]:=0;
  for i:=1 to n-1 do begin
    a[1,i+1]:=i;
    getsim(1,i+1);
  end;
  for j:=3 to n-1 do begin
    k:=a[1,j];
    for i:=2 to j-1 do begin
      inc(k);
      if k=n then k:=1;
      a[i,j]:=k;
      str[i,k]:=1;
      getsim(i,j);
    end;
  end;
  for i:=2 to n-1 do 
    for j:=1 to n-1 do
      if str[i,j]<>1 then begin
        a[i,n]:=j;
        getsim(i,n);
      end;
  for i:=1 to n do begin
    if i<>1 then writeln('');
    for j:=1 to n do
      write(a[i,j],' ');
  end;
end.
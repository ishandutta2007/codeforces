var n,i,j,f,k:longint;
    x:string;
    a,b,c:array [0..100001] of string;
    p:array [1..100001] of longint;
    
begin  
  readln(n);
  
  For i:= 1 to n  do 
  begin
    readln(a[i]);
    for j:=1 to length(a[i]) do 
      If a[i][j]=' ' then
      begin
        b[i]:=copy(a[i],j+1,length(a[i])-j+1);
        a[i]:=copy(a[i],1,j-1);
        break;
      end;
If a[i]>b[i] then 
        begin
          x:=a[i];
          a[i]:=b[i];
          b[i]:=x;
        end;
  end;
  
  For i:=1 to n do read(p[i]);
  
  If a[p[1]]<b[p[1]] then c[1]:=a[p[1]] else c[1]:=b[p[1]];
  k:=1;
  For i:=2 to n do 
    If c[i-1]<a[p[i]] then 
    begin
      k:=k+1;
      c[k]:=a[p[i]]
    end else
    If c[i-1]<b[p[i]] then 
    begin
      k:=k+1;
      c[k]:=b[p[i]]
    end else 
    begin
      f:=1;
      break;
    end;
    
  If f=0 then write('YES') else write('NO');
end.
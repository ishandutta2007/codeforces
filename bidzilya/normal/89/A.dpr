var 
  i:integer;
  ans,tmp,n,m,k:int64;
  
begin
    read(n,m,k);
    if n mod 2=0 then begin writeln('0'); halt; end;
    ans:=k*(m div((n+1)div 2));
    for i:=1 to n do begin
        read(tmp);
        if (i mod 2=1)and(tmp<ans)then ans:=tmp;
    end;
    write(ans);
end.
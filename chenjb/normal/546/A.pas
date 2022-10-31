var
  k,n,w:int64;
  ans:int64;
begin
  readln(k,n,w);
  ans:=(1+w)*w div 2;
  ans:=ans*k;
  ans:=ans-n;
  if ans<0 then ans:=0; 
  writeln(ans);
end.
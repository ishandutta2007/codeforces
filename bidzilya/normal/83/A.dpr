var
  n,j,k,i,l:integer;
  sm:int64;
  
function getsm(i:integer):int64;
begin
  result:=1+k;
  result:=int64(result*k);
  result:=result div 2;
end;
 
begin
  read(n);
  sm:=0;
  read(l);
  k:=1;
  for j:=2 to n do begin
    read(i);
    if i<>l then begin sm:=sm+getsm(k); l:=i; k:=1; end else inc(k);
  end;
  sm:=sm+getsm(k);
  write(sm);
end.
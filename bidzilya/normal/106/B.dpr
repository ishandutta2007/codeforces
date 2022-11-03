var
  speed,ram,hdd,cost:array[1..100]of integer;
  n,ind,i,j:integer;
  
begin
  read(n);
  for i:=1 to n do 
    read(speed[i],ram[i],hdd[i],cost[i]);
  for i:=1 to n do
    for j:=1 to n do
      if (speed[i]<speed[j])and(ram[i]<ram[j])and(hdd[i]<hdd[j])then begin
        cost[i]:=maxint;
        break;
      end;
  j:=maxint;
  ind:=-1;
  for i:=1 to n do
    if cost[i]<j then begin
      j:=cost[i];
      ind:=i;
    end;
  write(ind);
end.
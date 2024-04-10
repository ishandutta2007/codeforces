program task_b;

{$APPTYPE CONSOLE}

var t: array[-10..10]of int64;
    n,i,j: integer;
    ans: int64;

begin
  read(n);
  for i:=-10 to 10 do t[i]:=0;
  for i:=1 to n do begin
    read(j);
    inc(t[j]);
  end;
  ans:=0;
  for i:=-10 to -1 do begin
    j:=-i;
    ans:=ans+t[j]*t[i];
  end;
  ans:=ans+t[0]*(t[0]-1)div 2;
  write(ans);
end.
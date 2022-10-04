program Task_B;
var
t1,t2:array[1..49] of Integer;
t:array[1..50] of Integer;
min,min2,n,i,this,j:Integer;
begin
   Readln(n);
   min:=1000000000;
   min2:=1000000000;
   for i:=1 to n-1 do
     Read(t1[i]);
   for i:=1 to n-1 do
     Read(t2[i]);
   for i:=1 to n do
     Read(t[i]);
   for i:=1 to n do
   begin
        this:=0;
        for j:=1 to i-1 do
          inc(this,t1[j]);
        inc(this,t[i]);
        for j:=i to n-1 do
          inc(this,t2[j]);
        if this<=min then
        begin
          min2:=min;
          min:=this;
        end
        else
        begin
          if this<min2 then
          begin
            min2:=this;
          end;
        end;
   end;
   Writeln(min+min2);
end.
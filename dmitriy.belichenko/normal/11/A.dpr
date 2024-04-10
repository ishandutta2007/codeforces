var 
a , prev , next , n , d , I : integer;
begin
a:= 0;
read(n , d);
read(prev);
for i := 1 to n - 1 do
 begin 
 read(next);
if(prev >= next) then
begin
 a := a + ((prev- next) div d) + 1;
 next :=next + (-(next - prev) div d + 1) * d;
end;
 prev := next;
end;
 writeln(a);
end.
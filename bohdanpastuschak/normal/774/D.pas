var a:array[1..100005]of longint;
	b:array[1..100005]of longint;
    r,t,l,n:longint;
	i:longint;
begin
read(n);
read(l);
read(r);
t:=0;
for i:=1 to n do 
read(a[i]);
for i:=1 to n do 
read(b[i]);
for i:=1 to n do 
begin;
	if (i<l)or(i>r) then
		if (a[i] <> b[i]) then
		begin;
		if(t=0) then
		write('LIE');
		t:=1;
		end;
end;
if (t=0) then
write('TRUTH');
end.
type Tbox = record
  c:char;
  num:integer;
end;
var
  s:string;
  sm,k,i,j,n:integer;
  l:char;
  c:array['a'..'z']of integer;
  a:array[1..26]of Tbox;
  bol:boolean;
  
begin
  readln(s);
  read(k);
  for l:='a' to 'z' do
    c[l]:=0;
  for i:=1 to length(s) do
    inc(c[s[i]]);
  n:=0;
  for l:='a' to 'z' do 
    if c[l]<>0 then begin
      inc(n);
      a[n].num:=c[l];
      a[n].c:=l;
    end;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[j].num>a[i].num then begin
        sm:=a[j].num;
        l:=a[j].c;
        a[j].c:=a[i].c;
        a[i].c:=l;
        a[j].num:=a[i].num;
        a[i].num:=sm;
      end;
  while (k>0)and(n>0)do 
    if k>=a[n].num then begin
      k:=k-a[n].num;
      dec(n);
    end else begin
      a[n].num:=a[n].num-k;
      k:=0;
    end;
  sm:=n;
  writeln(sm);
  for i:=1 to length(s) do begin
    bol:=true;
    for j:=1 to n do
      if (s[i]=a[j].c)and(a[j].num>0) then begin bol:=false; dec(a[j].num); break; end;
    if not bol then write(s[i]);
  end;
end.
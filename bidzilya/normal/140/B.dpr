{$APPTYPE CONSOLE}

var
  i,j,l,n,k,ind:integer;
  bol:boolean;
  a:array[1..300,1..300]of integer;
  t:array[1..300]of integer;
begin
  //assign(input,'input.txt');reset(input);
 // assign(output,'output.txt');rewrite(output);
  readln(n);
  for i:=1 to n do
    for j:=1 to n do
      read(a[i,j]);
  for i:=1 to n do read(t[i]);
  for i:=1 to n do
    for j:=1 to n do
      begin
        if (a[i,j]=i)then continue;
        bol:=true;
        k:=1;
        while (t[k]<>a[i,j])do
          begin
            if (t[k]<a[i,j])and(t[k]<>i)then
              bol:=false;
            inc(k);
          end;
        if (bol)then
          begin
            write(a[i,j],' ');
            break;
          end;
      end;
end.
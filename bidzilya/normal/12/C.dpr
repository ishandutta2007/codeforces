type Tbox = record
    name:string;
    num:integer;
end;
var
    sp:array[1..100]of Tbox;
    c:array[1..100]of integer;
    i,j,n,m,tmp,a,b,num:integer;
    s:string;
    bol:boolean;
    
begin
    //assign(input,'input.txt');
    //reset(input);
    readln(n,m);
    for i:=1 to n-1 do
      read(c[i]);
    readln(c[n]);
    num:=0;
    for i:=1 to m do begin
      readln(s);
      bol:=true;
      for j:=1 to num do 
        if sp[j].name=s then begin
          inc(sp[j].num);
          bol:=false;
          break;
        end;
      if bol then begin
        inc(num);
        sp[num].name:=s;
        sp[num].num:=1;
      end;
   end;
   for i:=1 to n-1 do
    for j:=i+1 to n do
      if c[j]<c[i] then begin
        tmp:=c[i];
        c[i]:=c[j];
        c[j]:=tmp;
      end;
   for i:=1 to num-1 do
    for j:=i+1 to num do
      if sp[j].num>sp[i].num then begin
        tmp:=sp[i].num;
        sp[i].num:=sp[j].num;
        sp[j].num:=tmp;
        
        s:=sp[i].name;
        sp[i].name:=sp[j].name;
        sp[j].name:=s;
      end;
   a:=0;
   for i:=1 to num do
    a:=sp[i].num*c[i]+a;
   b:=0;
   for i:=1 to num do
    b:=sp[i].num*c[n-i+1]+b;
   write(a,' ',b);
end.
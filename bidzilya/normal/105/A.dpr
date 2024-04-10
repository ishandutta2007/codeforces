uses SysUtils;
const exp=1e-10;
var
  name:array[1..40]of string;
  zn:array[1..40]of integer;
  n,m,i,p,num,tmp:integer;
  s:string;
  bol:boolean;
  k,tk:real;
  
begin
  //assign(input,'input.txt');reset(input);
  readln(n,m,k);
  num:=0;
  for i:=1 to n do begin
    readln(s);
    p:=pos(' ',s);
    tmp:=strtoint(copy(s,p+1,length(s)-p));
    s:=copy(s,1,p-1);
    tk:=tmp*k;
    tmp:=round(tk);
    if tmp-tk>exp then dec(tmp);
    if tmp>=100 then begin
      inc(num);
      name[num]:=s;
      zn[num]:=tmp;
    end;
  end;
  for i:=1 to m do begin
    readln(s);
    bol:=false;
    for tmp:=1 to num do
      if name[tmp]=s then bol:=true;
    if not bol then begin
      inc(num);
      name[num]:=s;
      zn[num]:=0;
    end;
  end;
  
  for i:=1 to num-1 do
    for tmp:=i+1 to num do
      if name[tmp]<name[i] then begin
        s:=name[tmp];
        name[tmp]:=name[i];
        name[i]:=s;
        p:=zn[tmp];
        zn[tmp]:=zn[i];
        zn[i]:=p;
      end;
  writeln(num);
  for i:=1 to num do begin
    write(name[i],' ');
    writeln(zn[i]);
  end;
end.
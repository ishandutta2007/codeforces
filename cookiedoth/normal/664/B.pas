type LOL=record
  plus:boolean;
  num:integer;
end;
var
  s:string;
  m:array[1..100] of LOL;
  i,n,k,q,kpl,kmn:integer;
begin
  readln(s);
  k:=1;
  m[1].num:=1;
  m[1].plus:=true;
  for i:=1 to length(s) do
  begin
    if (s[i]='+') or (s[i]='-') then
    begin
      inc(k);
      m[k].num:=1;
      if s[i]='+' then m[k].plus:=true else m[k].plus:=false;
    end;
    if s[i]='=' then begin q:=i; break; end;
  end;
  val(copy(s,q+1,length(s)-q),n,kpl);
  kpl:=0; kmn:=0;
  q:=0;
  for i:=1 to k do
  begin
    if m[i].plus then
    begin
      inc(q);
      inc(kpl);
    end
    else
    begin
      dec(q);
      inc(kmn);
    end;
  end;
  if n<>q then
  begin
    for i:=1 to k do
    begin
      if (n>q) and (m[i].plus=true) then
      begin
        if q>1 then 
        begin
          inc(m[i].num,n-q);
          q:=n;
        end
        else 
        begin
          m[i].num:=n;
          inc(q,n-1);
        end;
      end;
      if (n<q) and (m[i].plus=false) then
      begin
        if q-n<n-1 then 
        begin
          inc(m[i].num,q-n);
          q:=n;
        end
        else 
        begin
          m[i].num:=n;
          dec(q,n-1);
        end;
      end;
    end;
  end;
  if q<>n then begin writeln('Impossible'); halt(0); end;
  writeln('Possible');
  write(m[1].num,' ');
  for i:=2 to k do
  begin
    if m[i].plus then write('+ ') else write('- ');
    write(m[i].num);
    write(' ');
  end;
  write('= ');
  write(n);
end.
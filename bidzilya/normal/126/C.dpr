program task_3;

{$APPTYPE CONSOLE}

var map: array[1..2000,1..2000]of integer;
    stl,str,t: array[1..2000]of integer;
    ans,n,i,j: integer;
    c:char;
begin
//assign(input,'input.txt');reset(input);
//assign(output,'output.txt');rewrite(output);
  readln(n);
  for i:=1 to n do begin
    for j:=1 to n do begin
      read(c);
      map[i,j]:=ord(c)-ord('0');
    end;
    readln;
  end;
  fillchar(stl,sizeof(stl),0);
  fillchar(str,sizeof(str),0);
  fillchar(t,sizeof(T),0);
  ans:=0;
  for i:=1 to n do
    for j:=n downto i+1 do
      if ((stl[j]+str[i])mod 2<>map[i,j])then begin
        inc(stl[j]);
        inc(str[i]);
        inc(t[j]);inc(t[i]);
        inc(ans);
      end;
  fillchar(str,sizeof(str),0);
  fillchar(stl,sizeof(stl),0);
  for i:=n downto 1 do
    for j:=1 to i-1 do
      if ((stl[j]+str[i])mod 2<>map[i,j])then begin
        inc(ans);
        inc(stl[j]);
        inc(str[i]);
        inc(t[j]);
        inc(t[i]);
      end;
  for i:=1 to n do
    if (t[i] mod 2<>map[i,i])then
      inc(ans);
  write(ans);
end.
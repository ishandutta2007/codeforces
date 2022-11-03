program task_2;

{$APPTYPE CONSOLE}
var p: array[1..1000000]of integer;
    i,j,n: integer;
    s: string;

begin
//assign(input,'input.txt');reset(input);
//assign(output,'output.txt');rewrite(output);
  readln(s);
  n:=length(s);
  p[1]:=0;
  for i:=2 to n do begin
    j:=p[i-1];
    while (j>0)and(s[j+1]<>s[i])do j:=p[j];
    if (s[j+1]=s[i])then inc(j);
    p[i]:=j;
  end;
  if (p[n]=0)then begin
    writeln('Just a legend');
    halt;
  end;
  for i:=p[n]+1 to n-1 do
    if (p[i] = p[n])then begin
      writeln(copy(s,1,p[n]));
      halt;
    end;
  j:=p[p[n]];
  if (j =0)then begin
    writeln('Just a legend');
    halt;
  end;
  writeln(copy(s,1,j));
end.
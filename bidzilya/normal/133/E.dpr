program task_e;

{$APPTYPE CONSOLE}
uses Math;
const maxint = 10000;
var p: string;
    n,ans,k,h,i,j,t: integer;
    f: array[0..100,-100..100,0..51,-1..1]of boolean;
begin
//assign(input,'input.txt');reset(input);
//assign(output,'output.txt');rewrite(output);
  readln(p);
  read(k);
  n:=length(p);
  fillchar(f,sizeof(f),false);
  f[0,0,0,1]:=true;
  for i:=1 to n do
    for j:=-100 to 100 do
      for t:=-1 to 1 do
        if (t<>0)then
          for h:=0 to k do
            if (f[i-1,j,h,t])then begin
              if (p[i]='F')then begin
                f[i,j+t,h,t]:=true;
                f[i,j,h+1,-t]:=true;
              end;
              if (p[i]='T')then begin
                f[i,j+t,h+1,t]:=true;
                f[i,j,h,-t]:=true;
              end;
            end;
  t:=k mod 2;
  ans:=0;
  while (t<=k)do begin
    for i:=-100 to 100 do
      for j:=-1 to 1 do
        if (j<>0)and(f[n,i,t,j])then ans:=max(ans,abs(i));
    inc(t,2);
  end;
  write(ans);
end.
program task_2;

{$APPTYPE CONSOLE}

const nmax = 100000;
var q,plus,min: array[1..nmax]of integer;
    qm,qp: array[1..nmax]of string;
    c:array[1..nmax]of char;
    used: array[1..nmax]of boolean;
    km,len,kp,m,n,i,j: integer;

procedure go(var v: string; t: string);
begin
  if (v <> '')and(v<>t)then
    v:='Not defined'
  else
    v:=t;
end;
begin
//assign(input,'input.txt');reset(input);
//assign(output,'output.txt');rewrite(output);
  readln(n,m);
  fillchar(min,sizeof(min),0);
  fillchar(plus,sizeof(plus),0);
  for i:=1 to n do begin
    readln(c[i],q[i]);
    if (c[i] = '+')then inc(plus[q[i]])
      else inc(min[q[i]]);
  end;
  km:=0;
  for i:=1 to n do
    inc(km,min[i]);
  kp:=0;
  for i:=1 to n do
    inc(kp,plus[i]);
  for i:=1 to n do begin
    qm[i]:='';
    qp[i]:='';
  end;
  len:=0;
{  for i:=1 to n do
    if (plus[i]+km-min[i] = m)then begin
      go(qp[i],'Truth');
      go(qm[i],'Lie');
      for j:=1 to n do
        if (j<>i)then begin
          go(qp[j],'Lie');
          go(qm[j],'Truth');
        end;
    end;}
  fillchar(used,sizeof(used),false);
  for i:=1 to n do
    if (plus[i]+km-min[i] = m)then begin
      inc(len);
      used[i]:=true;
    end;
  for i:=1 to n do begin
    if (used[i])and(len<>1)then qp[i]:='Not defined'
      else if (used[i])and(len = 1)then qp[i]:='Truth'
        else qp[i]:='Lie';
    if (used[i])and(len<>1)then qm[i]:='Not defined'
      else if (used[i])and(len = 1)then qm[i]:='Lie'
        else qm[i]:='Truth';
  end;
  for i:=1 to n do
    if (c[i]='+')then writeln(qp[q[i]])
      else writeln(qm[q[i]]);
end.
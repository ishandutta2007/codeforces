uses math;

const maxn = 101010;
var 
  a, b: array[0..maxn] of int64;

function cal_delta(i, j: longint): int64;
begin
  exit(-a[i] + b[i] + a[j] - b[j]);
end;

type h_node = record
  left: ^h_node;
  right: ^h_node;
  val: longint;
end;
type ph_node = ^h_node;

function make_heap(x: longint): ph_node;
var
  res: ph_node;
begin
  new(res);
  res^.left := nil;
  res^.right := nil;
  res^.val := x;
  exit(res);
end;

procedure free_heap(u: ph_node);
begin
  if u = nil then exit();
  free_heap(u^.left); free_heap(u^.right);
  dispose(u);
end;

function join(u: ph_node; v: ph_node): ph_node;
var
  t: ph_node;
begin
  if u = nil then exit(v);
  if v = nil then exit(u);
  if cal_delta(u^.val, v^.val) > 0 then begin   // sort order
    t := u; u := v; v := t; end;
  if random(2) = 1 then begin
    t := u^.right; u^.right := u^.left; u^.left := t;
  end;
  u^.right := join(u^.right, v);
  exit(u);
end;

procedure push(var h: ph_node; val: longint);
begin h := join(h, make_heap(val)); end;

function pop(var h: ph_node): longint;
var t: ph_node;
begin
  t := h;
  h := join(h^.left, h^.right);
  pop := t^.val;
  dispose(t);
end;

var n: longint;
var i, f: longint;
var heap: ph_node = nil;
var ans: int64;
begin
  randomize;
  read(n);
  for i := 1 to n do read(a[i], b[i]);
  for i := 1 to n do push(heap, i);
  ans := 0;
  for i := 1 to n do begin
    f := pop(heap);
    inc(ans, a[f] * (i - 1) + b[f] * (n - i));
  end;
  writeln(ans);
end.
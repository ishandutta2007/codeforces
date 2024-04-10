a = gets.split.map {|s| s.to_i}
b = gets.split.map {|s| s.to_i}

$x1, $x2 = [a[0], a[2], a[4], a[6]].minmax
$y1, $y2 = [a[1], a[3], a[5], a[7]].minmax

$x3 = (b[0] + b[2] + b[4] + b[6]) / 4.0
$y3 = (b[1] + b[3] + b[5] + b[7]) / 4.0
$r = (b[0] - $x3).abs + (b[1] - $y3).abs

def a_contains x, y
  x >= $x1 and x <= $x2 and y >= $y1 and y <= $y2
end

def b_contains x, y
  (x - $x3).abs + (y - $y3).abs <= $r
end

def clamp x, y, z
  if y > z then y, z = z, y end
  [[x, y].max, z].min
end

a.push a[0], a[1]
puts (0..7).step(2).any? {|i|
  a_contains(b[i], b[i + 1]) ||
  b_contains(a[i], a[i + 1]) ||
  b_contains(clamp($x3, a[i], a[i + 2]), a[i + 1]) ||
  b_contains(a[i], clamp($y3, a[i + 1], a[i + 3]))
} ? 'Yes' : 'No'
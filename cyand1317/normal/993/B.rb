def read_ints
  gets.chomp.split.map {|s| s.to_i}
end

n, m = read_ints
a = read_ints
b = read_ints

ans = []
amb = false

def shares_one p, q, r, s
  ret = nil
  if p == r || p == s then ret = p end
  if q == r || q == s then ret = (ret == nil ? q : nil) end
  return ret
end

for i in 0...n do
  for j in 0...m do
    x = shares_one a[i * 2], a[i * 2 + 1], b[j * 2], b[j * 2 + 1]
    if x != nil then
      cand = []
      for k in 0...m do
        y = shares_one a[i * 2], a[i * 2 + 1], b[k * 2], b[k * 2 + 1]
        if y != nil then cand.push y end
      end
      for k in 0...n do
        y = shares_one a[k * 2], a[k * 2 + 1], b[j * 2], b[j * 2 + 1]
        if y != nil then cand.push y end
      end
      cand.uniq!
      if cand.length == 1 then
        ans.push cand[0]
      else
        amb = true
      end
    end
  end
end

ans.uniq!
if amb then
  puts -1
elsif ans.length == 1 then
  puts ans[0]
else
  puts 0
end
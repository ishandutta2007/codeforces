n=gets.to_i
a=Array.new(n)
for i in 0...n
	a[i]=gets.chomp.split.sort
end
cur,ans='','YES'
for i in gets.chomp.split.map(&:to_i)
	if a[i-1][0] > cur
		cur = a[i-1][0]
	elsif a[i-1][1] > cur
		cur = a[i-1][1]
	else
		ans = 'NO'
	end
end
puts ans
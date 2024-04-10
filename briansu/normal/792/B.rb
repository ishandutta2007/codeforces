n,k=gets.split(" ").map(&:to_i)
a=gets.split(" ").map(&:to_i)
dt=(1..n).to_a

now=0

ans=[]

for i in (0...k)
	tmp=a[i]%dt.length
	now=(now+tmp)%dt.length
	ans<<dt.delete_at(now)
end
puts ans.join(" ")
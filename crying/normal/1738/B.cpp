__asm__(R"(
	.file	"E.cpp"
	.section	.text$_Z4Readv,"x"
	.linkonce discard
	.globl	_Z4Readv
	.def	_Z4Readv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4Readv
_Z4Readv:
.LFB33:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$1, %esi
	orl	$-1, %edi
.L2:
	call	getchar
	leal	-48(%rax), %edx
	movb	%al, %bl
	cmpb	$9, %dl
	jbe	.L13
	cmpb	$45, %al
	cmove	%edi, %esi
	jmp	.L2
.L13:
	xorl	$48, %ebx
	movsbl	%bl, %ebx
.L9:
	call	getchar
	leal	-48(%rax), %edx
	cmpb	$9, %dl
	ja	.L14
	leal	(%rbx,%rbx), %edx
	xorl	$48, %eax
	leal	(%rdx,%rbx,8), %edx
	movsbl	%al, %ebx
	addl	%edx, %ebx
	jmp	.L9
.L14:
	movl	%ebx, %eax
	imull	%esi, %eax
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.section	.text$_Z4Initv,"x"
	.linkonce discard
	.globl	_Z4Initv
	.def	_Z4Initv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4Initv
_Z4Initv:
.LFB36:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	_Z4Readv
	movl	%eax, n(%rip)
	call	_Z4Readv
	movl	n(%rip), %ebx
	movl	%eax, k(%rip)
	subl	%eax, %ebx
.L20:
	movl	n(%rip), %edx
	incl	%ebx
	cmpl	%edx, %ebx
	jg	.L21
	call	_Z4Readv
	leaq	s(%rip), %rdx
	movslq	%ebx, %rcx
	movl	%eax, (%rdx,%rcx,4)
	jmp	.L20
.L21:
	movl	%edx, %eax
	subl	k(%rip), %eax
	addl	$2, %eax
.L18:
	cmpl	%edx, %eax
	jg	.L22
	leal	-1(%rax), %r8d
	leaq	s(%rip), %r10
	movslq	%eax, %r9
	incl	%eax
	movslq	%r8d, %r8
	movl	(%r10,%r9,4), %ecx
	subl	(%r10,%r8,4), %ecx
	leaq	a(%rip), %r8
	movl	%ecx, (%r8,%r9,4)
	jmp	.L18
.L22:
	addq	$32, %rsp
	popq	%rbx
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "No\0"
.LC1:
	.ascii "Yes\0"
	.section	.text$_Z5Solvev,"x"
	.linkonce discard
	.globl	_Z5Solvev
	.def	_Z5Solvev;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5Solvev
_Z5Solvev:
.LFB37:
	pushq	%rbx
	.seh_pushreg	%rbx
	.seh_endprologue
	movl	n(%rip), %r9d
	movl	k(%rip), %r8d
	movl	%r9d, %eax
	subl	%r8d, %eax
	leal	2(%rax), %ecx
	movl	%ecx, %edx
.L24:
	cmpl	%r9d, %edx
	jge	.L30
	leaq	a(%rip), %r10
	movslq	%edx, %rbx
	incl	%edx
	movslq	%edx, %r11
	movl	(%r10,%r11,4), %r11d
	cmpl	%r11d, (%r10,%rbx,4)
	jle	.L24
.L27:
	leaq	.LC0(%rip), %rcx
	jmp	.L29
.L30:
	decl	%r8d
	jle	.L26
	leaq	a(%rip), %rdx
	movslq	%ecx, %rcx
	incl	%eax
	cltq
	movslq	(%rdx,%rcx,4), %rdx
	leaq	s(%rip), %rcx
	imulq	%rax, %rdx
	movslq	(%rcx,%rax,4), %rax
	cmpq	%rax, %rdx
	jl	.L27
.L26:
	leaq	.LC1(%rip), %rcx
.L29:
	popq	%rbx
	jmp	puts
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB38:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	call	__main
	call	_Z4Readv
	movl	%eax, T(%rip)
.L32:
	cmpl	$0, T(%rip)
	je	.L34
	call	_Z4Initv
	call	_Z5Solvev
	decl	T(%rip)
	jmp	.L32
.L34:
	xorl	%eax, %eax
	addq	$40, %rsp
	ret
	.seh_endproc
	.globl	T
	.bss
	.align 4
T:
	.space 4
	.globl	a
	.align 64
a:
	.space 400020
	.globl	k
	.align 4
k:
	.space 4
	.globl	n
	.align 4
n:
	.space 4
	.globl	s
	.align 64
s:
	.space 400020
	.ident	"GCC: (tdm64-1) 4.9.2"
	.def	getchar;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef

)");